library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity adder_subtractor_4bits is
    port(
        X, Y: in STD_LOGIC_VECTOR(3 downto 0);
        MODE, Cin: in STD_LOGIC;
        S: out STD_LOGIC_VECTOR(3 downto 0);
        Cout: out STD_LOGIC
    );
end adder_subtractor_4bits;

architecture adder_subtractor_4bits of adder_subtractor_4bits is
    signal temp: STD_LOGIC_VECTOR(4 downto 0);
begin
    process(X, Y)
        begin
            if MODE = '0' then
                temp <= ('0' & X) + Y + Cin;
                S <= temp(3 downto 0);
                Cout <= temp(4);
            else
                S <= X - Y - Cin;
                if X < Y then
                    Cout <= '1';
                else Cout <= '0';
                end if;
            end if;
        end process;
end adder_subtractor_4bits;
