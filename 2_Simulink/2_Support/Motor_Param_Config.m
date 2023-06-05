% %   F28069M
    PWM_frequency               = 20e3;                 %%Hz          // converter s/w freq
    inverter.DeadTime           = 1e-6;                 %s      //deadbound time

    Target.model                = 'LAUNCHXL-F28069M';	% 		// Manufacturer Model Number
    Target.sn                   = '123456';          	% 		// Manufacturer Serial Number
    Target.CPU_frequency        = 90e6;    				%Hz     // Clock frequency
    Target.PWM_frequency        = PWM_frequency;   		%Hz     // PWM frequency
    Target.PWM_Counter_Period   = round(Target.CPU_frequency/Target.PWM_frequency/2); % //PWM timer counts for up-down counter
    Target.PWM_Counter_Period   = Target.PWM_Counter_Period+mod(Target.PWM_Counter_Period,2); % // Count value needs to be even
    Target.ADC_Vref             = 3.3;					%V		// ADC voltage reference
    Target.ADC_MaxCount         = 4095;					%		// Max count for 12 bit ADC
    Target.SCI_baud_rate        = 5.625e6;              %Hz     // Set baud rate for serial communication
    Target.PWM_CPMA_InitVal     = floor(Target.PWM_Counter_Period/2+1);% //PWM duty inital Value 50%;    
    Target.Deadband             = floor(inverter.DeadTime*Target.CPU_frequency/2); 