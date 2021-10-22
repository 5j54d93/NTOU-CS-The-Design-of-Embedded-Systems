library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity adder_subtractor_4bits is
    port(
        A: in STD_LOGIC_VECTOR(3 downto 0);
        B: in STD_LOGIC_VECTOR(3 downto 0);
        M: in STD_LOGIC;
        S: out STD_LOGIC_VECTOR(3 downto 0);
        Co: out STD_LOGIC
        );
end adder_subtractor_4bits;

architecture adder_subtractor_4bits of adder_subtractor_4bits is
    signal C1, C2, C3: STD_LOGIC;
begin
    S(0) <= A(0) xor B(0) when M = '0' else
            A(0) xor (not B(0)) xor '1';
    
end adder_subtractor_4bits;
