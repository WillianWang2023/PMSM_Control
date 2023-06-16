classdef EInverterState < Simulink.IntEnumType
    enumeration
       INIT(1)
       Ready(2)
       FailureHandle(3)
       TorqueControl(4)
       SpeedControl(5)
       DebugHandle(6)
       ACDischarge(7)
       Sleep(8)
    end
end