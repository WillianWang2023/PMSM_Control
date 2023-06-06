



Lq = 0.000891;
Rs = 0.503;
Ld = 0.000891;
phi_r = 0.012;

Iq = 100;


Id = 0;
We = 2*pi*100;
N = [10 50 120];
Ts = 1/8000;
kp = (3*Ld./N/Ts-Rs)/Lq/Iq;
rs = kp*Lq*Iq;
n = 3*Ld/Rs/Ts;

ki1 = 2.96*Rs/sqrt(2)./N/Ts;
ki2 = 2.96*Rs/sqrt(2)./N/Ts*80;
ki = [ki1 ki2];
Ns = 2.96/(Rs/Lq/1.41421)/Ts;
Npi = [4 10 20];
kpi_p = 3*Lq./Npi/Ts;
kpi_i = 3*Rs./Npi/Ts;

kid_p = 3*Lq./Npi/Ts/Lq/Iq
kid_i = 3*Rs./Npi/Ts/Lq/Iq



