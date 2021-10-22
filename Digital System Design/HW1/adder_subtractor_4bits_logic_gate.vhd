library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity adder_subtractor_4bits_logic_gate is
    port(
        A: in STD_LOGIC_VECTOR(3 downto 0);
        B: in STD_LOGIC_VECTOR(3 downto 0);
        M: in STD_LOGIC;
        S: out STD_LOGIC_VECTOR(3 downto 0);
        Co: out STD_LOGIC
        );
end adder_subtractor_4bits_logic_gate;

architecture adder_subtractor_4bits_logic_gate of adder_subtractor_4bits_logic_gate is
    signal C1, C2, C3: STD_LOGIC;
begin
    S(0) <= A(0) xor B(0) when M = '0' else
            A(0) xor (not B(0)) xor '1';
    C1 <= A(0) and B(0) when M = '0' else
          A(0) or (not B(0));
    S(1) <= A(1) xor B(1) xor C1 when M = '0' else
            A(1) xor (not B(1)) xor C1;
    C2 <= (A(1) and B(1)) or (B(1) and C1) or (A(1) and C1) when M = '0' else
          (A(1) and (not B(1))) or ((not B(1)) and C1) or (A(1) and C1);
    S(2) <= A(2) xor B(2) xor C2 when M = '0' else
            A(2) xor (not B(2)) xor C2;
    C3 <= (A(2) and B(2)) or (B(2) and C2) or (A(2) and C2) when M = '0' else
          (A(2) and (not B(2))) or ((not B(2)) and C2) or (A(2) and C2);
    S(3) <= A(3) xor B(3) xor C3 when M = '0' else
            A(3) xor (not B(3)) xor C3;
    Co <= (A(3) and B(3)) or (B(3) and C3) or (A(3) and C3) when M = '0' else
          (A(3) and (not B(3))) or ((not B(3)) and C3) or (A(3) and C3);
end adder_subtractor_4bits_logic_gate;
