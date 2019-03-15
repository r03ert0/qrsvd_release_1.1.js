const {svd2qr, polar2qr, svd3qr, polar3qr} = require('./svdqr.js');

const m2x2 = [1,2,3,4];
const m3x3 = [1,2,3,4,5,6,7,8,10];
const nano2x2 = [1, 1e-7, 1e-7, 2];

console.log(svd2qr(m2x2));
console.log(polar2qr(m2x2));
console.log(svd3qr(m3x3));
console.log(polar3qr(m3x3));
console.log(svd2qr(nano2x2));
