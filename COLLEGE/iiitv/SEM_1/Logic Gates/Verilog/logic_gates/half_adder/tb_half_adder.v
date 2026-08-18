`timescale 1ns/1ps

module half_adder_tb;

reg a, b;
wire sum, carry;


half_adder uut (
    .a(a),
    .b(b),
    .sum(sum),
    .carry(carry)
);

initial begin
    $display("a b | sum carry");
    $display("----------------");

    // Test case 0
    a = 0; b = 0; #10;
    $display("%b %b |  %b    %b", a, b, sum, carry);

    // Test case 1
    a = 0; b = 1; #10;
    $display("%b %b |  %b    %b", a, b, sum, carry);

    // Test case 2
    a = 1; b = 0; #10;
    $display("%b %b |  %b    %b", a, b, sum, carry);

    // Test case 3
    a = 1; b = 1; #10;
    $display("%b %b |  %b    %b", a, b, sum, carry);

    $stop;
end

endmodule
