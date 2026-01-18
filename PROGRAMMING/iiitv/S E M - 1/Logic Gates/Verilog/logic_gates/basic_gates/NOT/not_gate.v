module not_gate (
    input a,
    output reg y
);
    always @ (a) begin
        y = ~a;
    end
endmodule