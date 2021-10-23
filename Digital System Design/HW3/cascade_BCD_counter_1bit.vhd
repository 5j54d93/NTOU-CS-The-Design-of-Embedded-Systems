library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity cascade_BCD_counter_1bit is
    port(
        CLK, RESET, CASIN: in STD_LOGIC;
        CASOUT: out STD_LOGIC;
        F: out STD_LOGIC_VECTOR(3 downto 0)
        );
end cascade_BCD_counter_1bit;

architecture cascade_BCD_counter_1bit of cascade_BCD_counter_1bit is
    signal count: STD_LOGIC_VECTOR(3 downto 0);
begin
    process(CLK, RESET)
        begin
            if RESET = '0' then
               count <= (others => '0');
            elsif rising_edge(CLK) then
                if CASIN = '1' then
                    if count = x"9" then
                        count <= x"0";
                    else count <= count + 1;
                    end if;
                end if;
            end if;
    end process;
    
    F <= count;
    CASOUT <= '1' when CASIN = '1' and count = "1001" else
              '0';
end cascade_BCD_counter_1bit;
