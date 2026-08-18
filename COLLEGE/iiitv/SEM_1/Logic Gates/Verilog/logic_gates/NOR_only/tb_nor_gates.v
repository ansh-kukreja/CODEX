`timescale 1ns/1ps

module tb_nor_gates;
    reg a, b;
    wire y_not, y_or, y_and, y_nand, y_xor, y_xnor;

    // Instantiate NOR-based gates
    not_nor  u1 (.a(a), .y(y_not));
    or_nor   u2 (.a(a), .b(b), .y(y_or));
    and_nor  u3 (.a(a), .b(b), .y(y_and));
    nand_nor u4 (.a(a), .b(b), .y(y_nand));
    xor_nor  u5 (.a(a), .b(b), .y(y_xor));
    xnor_nor u6 (.a(a), .b(b), .y(y_xnor));

    integer i;

    initial begin
        $dumpfile("dump.vcd");      
        $dumpvars(0, tb_nor_gates);

        $display("T | a b || NOT OR AND NAND XOR XNOR");
        $display("----------------------------------");

        // Loop through all 4 input combinations
        for (i = 0; i < 4; i = i + 1) begin
            {a, b} = i[1:0];
            #10;
            $display("%0t | %b %b ||  %b   %b   %b    %b    %b    %b",
                     $time, a, b,
                     y_not, y_or, y_and, y_nand, y_xor, y_xnor);
        end

        $finish;
    end
endmodule
