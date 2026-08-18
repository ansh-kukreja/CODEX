// =====================================
// NOT using NAND (behavioral equivalent)
// =====================================
module not_nand (
    input a,
    output reg y
);
    always @(*) begin
        y = ~a;   // behavioral NOT
    end
endmodule

// =====================================
// AND using NAND
// =====================================
module and_nand (
    input a, b,
    output reg y
);
    always @(*) begin
        y = a & b;   // behavioral AND
    end
endmodule

// =====================================
// OR using NAND
// =====================================
module or_nand (
    input a, b,
    output reg y
);
    always @(*) begin
        y = a | b;   // behavioral OR
    end
endmodule

// =====================================
// NOR using NAND
// =====================================
module nor_nand (
    input a, b,
    output reg y
);
    always @(*) begin
        y = ~(a | b);  // behavioral NOR
    end
endmodule

// =====================================
// XOR using NAND
// =====================================
module xor_nand (
    input a, b,
    output reg y
);
    always @(*) begin
        y = a ^ b;   // behavioral XOR
    end
endmodule

// =====================================
// XNOR using NAND
// =====================================
module xnor_nand (
    input a, b,
    output reg y
);
    always @(*) begin
        y = ~(a ^ b);  // behavioral XNOR
    end
endmodule
