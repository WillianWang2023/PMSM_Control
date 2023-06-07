% �ʸ�60kw���������
% �����60Kw����ֵ����90Kw���ת��2300rpm����ֵ5500rpm��6�Լ��������150,����ֵ����280A���ת��240Nm����ֵת��450Nm
% Rs = 0.021��Ld = 0.00026H��Lq = 0.00053H ��phi_r = 0.078
%--------------------------------------------------------------------------
Rs = 0.021*(1-0.0);
Ld = 0.00026;
Lq = 0.00053*(1+0.2);
phi_r = 0.078;
Flux = phi_r*30*2^0.5/pi;
fe = 100;       % Hz
We = 2*pi*fe;
N = 10;
Ts = 1/8000;
ki = 2.96*Rs/sqrt(2)/N/Ts;
NTs = 50;
kp = abs(300*Ld/NTs - Rs);

Rsr = 0.021;
Ldr = 0.00026;
Lqr = 0.00053;