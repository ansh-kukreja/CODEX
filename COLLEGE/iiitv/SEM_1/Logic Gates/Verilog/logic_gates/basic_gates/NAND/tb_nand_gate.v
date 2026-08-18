`timescale 1ns/1ps
module tb_nand_gate;
    reg a, b;
    wire y;

    nand_gate uut (.a(a), .b(b), .y(y));

    initial begin
        $display("A B | NAND");
        $display("------------");

        a=0; b=0; #10; $display("%b %b | %b", a,b,y);
        a=0; b=1; #10; $display("%b %b | %b", a,b,y);
        a=1; b=0; #10; $display("%b %b | %b", a,b,y);
        a=1; b=1; #10; $display("%b %b | %b", a,b,y);

        $finish;
    end
endmodule