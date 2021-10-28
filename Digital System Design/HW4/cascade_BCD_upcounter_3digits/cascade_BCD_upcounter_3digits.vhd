library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity cascade_BCD_upcounter_3digits is
    port(
        CLK, RESET, CASIN: in STD_LOGIC;
        CASOUT: out STD_LOGIC;
        F: out STD_LOGIC_VECTOR(11 downto 0)
    );
end cascade_BCD_upcounter_3digits;

architecture cascade_BCD_upcounter_3digits of cascade_BCD_upcounter_3digits is
    signal CASOUT1, CASOUT2: STD_LOGIC;
    component cascade_BCD_upcounter_4bits
    port(
        CLK, RESET, CASIN: in STD_LOGIC;
        CASOUT: out STD_LOGIC;
        F: out STD_LOGIC_VECTOR(3 downto 0)
    );
    end component;
begin
    COUNTER1: cascade_BCD_upcounter_4bits port map(CLK, RESET, CASIN, CASOUT1, F(3 downto 0));
    COUNTER2: cascade_BCD_upcounter_4bits port map(CLK, RESET, CASOUT1, CASOUT2, F(7 downto 4));
    COUNTER3: cascade_BCD_upcounter_4bits port map(CLK, RESET, CASOUT2, CASOUT, F(11 downto 8));
end cascade_BCD_upcounter_3digits;
