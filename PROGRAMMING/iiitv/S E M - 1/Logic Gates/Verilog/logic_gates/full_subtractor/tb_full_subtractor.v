`timescale 1ns/1ps

module tb_full_subtractor;
    reg a, b, bin;
    wire diff, bout;

    // Instantiate Full Subtractor
    full_subtractor uut (
        .a(a),
        .b(b),
        .bin(bin),
        .diff(diff),
        .bout(bout)
    );

    integer i;

    initial begin
        $dumpfile("dump.vcd");    // For GTKWave
        $dumpvars(0, tb_full_subtractor);

        $display("T | a b bin || Diff Bout");
        $display("-------------------------");

        // Loop through all 8 combinations
        for (i = 0; i < 8; i = i + 1) begin
            {a, b, bin} = i[2:0];
            #10;
            $display("%0t | %b %b  %b  ||   %b    %b",
                     $time, a, b, bin, diff, bout);
        end

        $finish;
    end
endmodule
