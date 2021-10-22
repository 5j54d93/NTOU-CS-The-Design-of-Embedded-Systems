library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

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
    signal temp: STD_LOGIC_VECTOR(4 downto 0);
begin
    temp <= ('0' & A) + B when M = '0' else
            ('0' & A) - B;
    S <= temp(3 downto 0);
    Co <= temp(4);
end adder_subtractor_4bits;
