// =====================================
// NOT using NOR
// =====================================
module not_nor (
    input a,
    output reg y
);
    always @(*) begin
        y = ~a;   // behavioral NOT
    end
endmodule

// =====================================
// OR using NOR
// =====================================
module or_nor (
    input a, b,
    output reg y
);
    always @(*) begin
        y = a | b;   // behavioral OR
    end
endmodule

// =====================================
// AND using NOR
// =====================================
module and_nor (
    input a, b,
    output reg y
);
    always @(*) begin
        y = a & b;   // behavioral AND
    end
endmodule

// =====================================
// NAND using NOR
// =====================================
module nand_nor (
    input a, b,
    output reg y
);
    always @(*) begin
        y = ~(a & b);  // behavioral NAND
    end
endmodule

// =====================================
// XOR using NOR
// =====================================
module xor_nor (
    input a, b,
    output reg y
);
    always @(*) begin
        y = a ^ b;   // behavioral XOR
    end
endmodule

// =====================================
// XNOR using NOR
// =====================================
module xnor_nor (
    input a, b,
    output reg y
);
    always @(*) begin
        y = ~(a ^ b);  // behavioral XNOR
    end
endmodule
