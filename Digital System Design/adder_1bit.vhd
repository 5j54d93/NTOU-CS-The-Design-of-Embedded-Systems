library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity adder_1bit is
    port(
        A: in STD_LOGIC;
        B: in STD_LOGIC;
        C: in STD_LOGIC;
        S: out STD_LOGIC;
        Co: out STD_LOGIC
        );
end adder_1bit;

architecture adder_1bit of adder_1bit is

begin
    S <= A xor B xor C;
    Co <= (A and B) or (B and C) or (A and C);
end adder_1bit;
