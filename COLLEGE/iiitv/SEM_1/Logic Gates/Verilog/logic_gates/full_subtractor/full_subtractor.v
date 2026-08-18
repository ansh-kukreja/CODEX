// Full Subtractor
module full_subtractor (
    input a, b, bin,      // minuend, subtrahend, borrow in
    output reg diff,      // difference
    output reg bout       // borrow out
);
    always @(*) begin
        // Difference = A ⊕ B ⊕ Bin
        diff = a ^ b ^ bin;

        // Borrow out = (~a & b) | (~(a ^ b) & bin)
        bout = ((~a) & b) | ((~(a ^ b)) & bin);
    end
endmodule
