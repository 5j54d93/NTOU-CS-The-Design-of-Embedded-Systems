library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity demux_8_to_1 is
    port(
        I: in STD_LOGIC_VECTOR(7 downto 0);
        S: in STD_LOGIC_VECTOR(2 downto 0);
        F: out STD_LOGIC
        );
end demux_8_to_1;

architecture demux_8_to_1 of demux_8_to_1 is
    signal x: STD_LOGIC_VECTOR(1 downto 0);
begin
    x(0) <= I(0) when S(1)='0' and S(0)='0' else
            I(1) when S(1)='0' and S(0)='1' else
            I(2) when S(1)='1' and S(0)='0' else
            I(3);
    x(1) <= I(4) when S(1)='0' and S(0)='0' else
            I(5) when S(1)='0' and S(0)='1' else
            I(6) when S(1)='1' and S(0)='0' else
            I(7);
    F <= x(0) when S(2)='0' else
         x(1);
end demux_8_to_1;
