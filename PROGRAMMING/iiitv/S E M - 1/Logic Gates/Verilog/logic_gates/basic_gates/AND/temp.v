// `timescale 1ns/1ps
// module tb_and;
//     reg a,b;
//     wire y;

//     and uut(.a(a), .b(b), .y(y));

//     initial begin
//         $display("A B | AND");
//         $display("-----------");

//         a=0; b=0; #10; $display("%b %b | %b", a,b,y);
//         a=0; b=1; #10; $display("%b %b | %b", a,b,y);
//         a=1; b=0; #10; $display("%b %b | %b", a,b,y);
//         a=1; b=1; #10; $display("%b %b | %b", a,b,y);

//         $finish;
//     end
// endmodule

module and_g(
    input a,b;
    output reg y;
);
    always @ (*) begin
        y = a & b;
    end
endmodule

