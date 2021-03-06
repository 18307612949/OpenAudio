/*
 * AudioFilterFIR_F32
 * 
 * Created: Chip Audette (OpenAudio) Feb 2017
 *    - Building from AudioFilterFIR from Teensy Audio Library (AudioFilterFIR credited to Pete (El Supremo))
 * 
 */

#ifndef _filter_fir_f32
#define _filter_fir_f32

#include "Arduino.h"
#include "AudioStream_F32.h"
#include "arm_math.h"

// Indicates that the code should just pass through the audio
// without any filtering (as opposed to doing nothing at all)
#define FIR_F32_PASSTHRU ((const float32_t *) 1)

#define FIR_MAX_COEFFS 200

class AudioFilterFIR_F32 : public AudioStream_F32
{
public:
  AudioFilterFIR_F32(void): AudioStream_F32(1,inputQueueArray), coeff_p(NULL) {
  }
  void begin(const float32_t *cp, int n_coeffs) {
    coeff_p = cp;
    // Initialize FIR instance (ARM DSP Math Library)
    if (coeff_p && (coeff_p != FIR_F32_PASSTHRU) && n_coeffs <= FIR_MAX_COEFFS) {
      arm_fir_init_f32(&fir_inst, n_coeffs, (float32_t *)coeff_p,  &StateF32[0], AUDIO_BLOCK_SAMPLES);
      //if (arm_fir_init_f32(&fir_inst, n_coeffs, (float32_t *)coeff_p,  &StateF32[0], AUDIO_BLOCK_SAMPLES) != ARM_MATH_SUCCESS) {
        // n_coeffs must be an even number, 4 or larger
        //coeff_p = NULL;
      //}
    }
  }
  void end(void) {
    coeff_p = NULL;
  }
  virtual void update(void);
private:
  audio_block_f32_t *inputQueueArray[1];

  // pointer to current coefficients or NULL or FIR_PASSTHRU
  const float32_t *coeff_p;

  // ARM DSP Math library filter instance
  arm_fir_instance_f32 fir_inst;
  float32_t StateF32[AUDIO_BLOCK_SAMPLES + FIR_MAX_COEFFS];
};


void AudioFilterFIR_F32::update(void)
{
  audio_block_f32_t *block, *b_new;

  block = AudioStream_F32::receiveReadOnly_f32();
  if (!block) return;

  // If there's no coefficient table, give up.  
  if (coeff_p == NULL) {
    AudioStream_F32::release(block);
    return;
  }

  // do passthru
  if (coeff_p == FIR_F32_PASSTHRU) {
    // Just passthrough
    AudioStream_F32::transmit(block);
    AudioStream_F32::release(block);
    return;
  }

  // get a block for the FIR output
  b_new = AudioStream_F32::allocate_f32();
  if (b_new) {
    arm_fir_f32(&fir_inst, (float32_t *)block->data, (float32_t *)b_new->data, AUDIO_BLOCK_SAMPLES);
    AudioStream_F32::transmit(b_new); // send the FIR output
    AudioStream_F32::release(b_new);
  }
  AudioStream_F32::release(block);
}

#endif


