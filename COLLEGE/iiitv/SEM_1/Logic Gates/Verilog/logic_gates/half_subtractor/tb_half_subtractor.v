`timescale 1ns/1ps

module tb_half_subtractor;
    reg a, b;
    wire diff, borrow;

    // Instantiate Half Subtractor
    half_subtractor uut (
        .a(a),
        .b(b),
        .diff(diff),
        .borrow(borrow)
    );

    integer i;

    initial begin
        $dumpfile("dump.vcd");   // For GTKWave
        $dumpvars(0, tb_half_subtractor);

        $display("T | a b || Diff Borrow");
        $display("----------------------");

        // Loop through all 4 combinations
        for (i = 0; i < 4; i = i + 1) begin
            {a, b} = i[1:0];
            #10;
            $display("%0t | %b %b ||   %b     %b",
                     $time, a, b, diff, borrow);
        end

        $finish;
    end
endmodule
