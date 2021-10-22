library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity BCD_counter_3bits_100_to_499 is
    port(
        CLK, RESET: in STD_LOGIC;
        BCD: out STD_LOGIC_VECTOR(11 downto 0)
        );
end BCD_counter_3bits_100_to_499;

architecture BCD_counter_3bits_100_to_499 of BCD_counter_3bits_100_to_499 is
    signal temp: STD_LOGIC_VECTOR(11 downto 0);
begin
    process(CLK, RESET)
    variable temp0, temp1, temp2: STD_LOGIC_VECTOR(3 downto 0);
        begin
            if RESET ='0' then
               temp2 := x"1";
               temp1 := x"0";
               temp0 := x"0";
            elsif rising_edge(CLK) then
                if temp2 = x"4" and temp1 = x"9" and temp0 = x"9" then
                   temp2 := x"1";
                   temp1 := x"0";
                   temp0 := x"0";
               elsif temp0 = x"9" then
                   if temp1 = x"9" then
                      temp2 := temp2 + 1;
                      temp1 := x"0";
                      temp0 := x"0";
                   else
                       temp1 := temp1 + 1;
                       temp0 := x"0";
                else temp0 := temp0 + 1;
                end if;
            end if;
        temp <= temp2 & temp1 & temp0;
    end process;
    BCD <= temp;
end BCD_counter_3bits_100_to_499;
