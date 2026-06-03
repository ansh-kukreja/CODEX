// Half Subtractor
module half_subtractor (
    input a, b,        // inputs
    output reg diff,   // difference = a ^ b
    output reg borrow  // borrow = ~a & b
);
    always @(*) begin
        diff   = a ^ b;       // XOR for difference
        borrow = (~a) & b;    // borrow occurs when a=0, b=1
    end
endmodule
