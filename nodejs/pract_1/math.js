var Cal = function(a, b, n = 0) {
    this.a = a;
    this.b = b;
    this.n = n;
};
Cal.prototype.suma = function() {
    console.log("la suma es ", a + b);
    if (this.n < 2) {
        this.n = this.n + 1;
        this.suma();
    }
}

module.exports = {
    name: "Modulo calculadora",
    cal: Cal
};