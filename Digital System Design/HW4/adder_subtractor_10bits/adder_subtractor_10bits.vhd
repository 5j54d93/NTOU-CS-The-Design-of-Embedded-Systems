library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity adder_subtractor_10bits is
    port(
        X, Y: in STD_LOGIC_VECTOR(9 downto 0);
        MODE, Cin: in STD_LOGIC;
        S: out STD_LOGIC_VECTOR(9 downto 0);
        Cout: out STD_LOGIC
    );
end adder_subtractor_10bits;

architecture adder_subtractor_10bits of adder_subtractor_10bits is
    signal LS: STD_LOGIC_VECTOR(3 downto 0);
    signal Cout1, Cout2, Cout3: STD_LOGIC;
    component adder_subtractor_4bits
    port(
        X, Y: in STD_LOGIC_VECTOR(3 downto 0);
        MODE, Cin: in STD_LOGIC;
        S: out STD_LOGIC_VECTOR(3 downto 0);
        Cout: out STD_LOGIC
    );
    end component;
begin
    ADDER_SUBTRACTOR_1: adder_subtractor_4bits port map(X(3 downto 0), Y(3 downto 0), MODE, Cin, S(3 downto 0), Cout1);
    ADDER_SUBTRACTOR_2: adder_subtractor_4bits port map(X(7 downto 4), Y(7 downto 4), MODE, Cout1, S(7 downto 4), Cout2);
    ADDER_SUBTRACTOR_3: adder_subtractor_4bits port map("00" & X(9 downto 8), "00" & Y(9 downto 8), MODE, Cout2, LS, Cout3);
    S(9 downto 8) <= LS(1 downto 0);
    Cout <= LS(2);
end adder_subtractor_4bits;
