library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity staircase_8bits is
    port(
        CLK, RESET: in STD_LOGIC;
        F: out STD_LOGIC_VECTOR(7 downto 0)
        );
end staircase_8bits;

architecture staircase_8bits of staircase_8bits is
    signal count: STD_LOGIC_VECTOR(3 downto 0);
begin
    process(CLK, RESET)
        begin
            if RESET = '0' then
               count <= (others => '0');
            elsif rising_edge(CLK) then
                if count = x"D" then
                   count <= x"0";
                else count <= count + 1;
                end if;
            end if;
    end process;
    
    F <= "00000001" when count = x"0" else
         "00000010" when count = x"1" else
         "00000100" when count = x"2" else
         "00001000" when count = x"3" else
         "00010000" when count = x"4" else
         "00100000" when count = x"5" else
         "01000000" when count = x"6" else
         "10000000" when count = x"7" else
         "01000000" when count = x"8" else
         "00100000" when count = x"9" else
         "00010000" when count = x"A" else
         "00001000" when count = x"B" else
         "00000100" when count = x"C" else
         "00000010"
end staircase_8bits;
