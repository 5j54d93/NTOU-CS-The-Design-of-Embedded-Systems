library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity adder_4bits_process is
    port(
        A, B: in STD_LOGIC_VECTOR(3 downto 0);
        S: out STD_LOGIC_VECTOR(3 downto 0);
        Co: out STD_LOGIC
        );
end adder_4bits_process;

architecture adder_4bits_process of adder_4bits_process is
    signal temp: STD_LOGIC_VECTOR(4 downto 0);
begin
    process(A, B)
        begin
            temp <= ('0' & A) + B;
            S <= temp(3 downto 0);
            Co <= temp(4);
    end process;
end adder_4bits_process;
