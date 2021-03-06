
%load data
fname = 'output_f2_armFFT.txt';
fname = 'output_f10_armFFT_DC0.5.txt';
disp(['loading ' fname]);
data=load(fname);

%parse data
Nfft=256;
real_sig = data(1:Nfft);offset=Nfft;
real_sig(:,2) = data(offset+[1:Nfft]); offset=offset+Nfft;
%rfft_sig = data(offset+[1:2:(2*Nfft)])+sqrt(-1)*data(offset+[2:2:(2*Nfft)]); offset = offset+2*Nfft;
%cfft_sig =  data(offset+[1:2:(2*Nfft)])+sqrt(-1)*data(offset+[2:2:(2*Nfft)]); offset = offset+2*Nfft;
rfft_sig = [data(offset+[1:2:(2*Nfft)]) data(offset+[2:2:(2*Nfft)])];offset = offset+2*Nfft;
cfft_sig = [data(offset+[1:2:(2*Nfft)]) data(offset+[2:2:(2*Nfft)])];offset = offset+2*Nfft;



%plot;
figure;setFigureTallPartWide;
subplot(4,1,1);
plot(real_sig(:,1));
title('Real Signal');
xlim([1 Nfft]);

subplot(4,1,2);
plot(real_sig(:,2));
title('RFFT (real sig)');
legend('Real','Imaginary');
xlim([1 Nfft]);

subplot(4,1,3);
plot(rfft_sig);
title('RFFT');
legend('Real','Imaginary');
xlim([1 Nfft]);

subplot(4,1,4);
plot(cfft_sig);
title('CFFT');
legend('Real','Imaginary');
xlim([1 Nfft]);

