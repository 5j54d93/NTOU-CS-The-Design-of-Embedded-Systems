library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity updown_counter_8bits_20_to_A0 is
    port(
        CLK, UP_DOWN, RESET: in STD_LOGIC;
        Q: out STD_LOGIC_VECTOR(7 downto 0)
        );
end updown_counter_8bits_20_to_A0;

architecture updown_counter_8bits_20_to_A0 of updown_counter_8bits_20_to_A0 is
    signal temp: STD_LOGIC_VECTOR(7 downto 0);
begin
    process(CLK, RESET)
        begin
           if RESET ='0' then
               temp <= x"20";
           elsif rising_edge(CLK) then
               if UP_DOWN = '0' then
                   if temp = x"A0" then
                       temp <= x"20";
                   else temp <= temp + 1;
                   end if;
               elsif temp = x"20" then
                   temp <= x"A0";
               else temp <= temp - 1;
               end if;
           end if;
     end process;
     Q <= temp;
end updown_counter_8bits_20_to_A0;
