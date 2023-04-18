% % Define the impulse response hA[n]
% n = 0:2; % Time indices for n = 0, 1, 2
% hA = [0.5, -1, 0.5]; % Corresponding values of hA[n]

% % Compute the frequency response using the Fourier transform
% H = fft(hA, 512); % Zero-pad the impulse response and compute the FFT
% H_mag = abs(H); % Compute the magnitude response

% % Define the frequency axis for plotting
% f = linspace(0, 1, length(H_mag));

% % Plot the magnitude response
% figure;
% plot(f, H_mag);
% xlabel('Normalized Frequency (cycles/sample)');
% ylabel('Magnitude');
% title('Magnitude Response of LTI Causal Digital Filter');
% grid on;


% % Define the frequency range (0 to pi)
% omega = linspace(0, 2*pi, 1000);

% % Compute the frequency response H(e^(jω))
% H_ejw = 0.5 - exp(-1i * omega) + 0.5 * exp(-1i * 2 * omega);

% % Compute the magnitude response |H(e^(jω))|
% magnitude_response = abs(H_ejw);

% % Plot the magnitude response
% figure;
% plot(omega/pi, magnitude_response); % Normalize the frequency axis by pi
% xlabel('Normalized Frequency (cycles/sample)');
% ylabel('Magnitude');
% title('Magnitude Response');
% grid on;

% Define the numerator and denominator polynomials
num = [1, 3, 2, 7];
den = conv([2, 3], conv([1, 0.5, 0.8], [1, 0.5, 0.8]));

% Create the transfer function
H = tf(poly(num), poly(den));

% Plot the pole-zero map
figure;
zplane(num, den);

% Print the poles and zeros
zeros = roots(num);
poles = roots(den);
disp('Zeros:');
disp(zeros);
disp('Poles:');
disp(poles);
