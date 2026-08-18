`timescale 1ns/1ps

module tb_nand_gates;
    reg a, b;
    wire y_not, y_and, y_or, y_nor, y_xor, y_xnor;

    // Instantiate NAND-based gates
    not_nand  u1 (.a(a), .y(y_not));
    and_nand  u2 (.a(a), .b(b), .y(y_and));
    or_nand   u3 (.a(a), .b(b), .y(y_or));
    nor_nand  u4 (.a(a), .b(b), .y(y_nor));
    xor_nand  u5 (.a(a), .b(b), .y(y_xor));
    xnor_nand u6 (.a(a), .b(b), .y(y_xnor));

    integer i;

    initial begin
        $dumpfile("dump.vcd");      // for GTKWave
        $dumpvars(0, tb_nand_gates);

        $display("T | a b || NOT AND OR NOR XOR XNOR");
        $display("---------------------------------");

        // Loop through all 4 input combinations
        for (i = 0; i < 4; i = i + 1) begin
            {a, b} = i[1:0];
            #10;
            $display("%0t | %b %b ||  %b   %b   %b   %b   %b    %b",
                     $time, a, b,
                     y_not, y_and, y_or, y_nor, y_xor, y_xnor);
        end

        $finish;
    end
endmodule
