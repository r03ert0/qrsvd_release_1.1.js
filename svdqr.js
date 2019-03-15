var em = require('./svd.js');
var polar2 = em.cwrap('polar2', null, ['number', 'number', 'number']);
var svd2 = em.cwrap('svd2', null, ['number', 'number', 'number', 'number']);
var polar3 = em.cwrap('polar3', null, ['number', 'number', 'number']);
var svd3 = em.cwrap('svd3', null, ['number', 'number', 'number', 'number']);
var TMPQR = [];

for(let i=0;i<4;i++) {
    let o = {p: em._malloc(9*8)};
    o.arr = new Float64Array(em.HEAPF64.buffer, o.p, 9);
    TMPQR.push(o);
}
const polar2qr = function(m) {
    TMPQR[0].arr.set(m);
    polar2(TMPQR[0].p,TMPQR[1].p,TMPQR[2].p);
    return {
        R: TMPQR[1].arr.slice(0,4),
        S: TMPQR[2].arr.slice(0,4)
    }
}
const svd2qr = function(m) {
    TMPQR[0].arr.set(m);
    svd2(TMPQR[0].p,TMPQR[1].p,TMPQR[2].p,TMPQR[3].p);
    return {
        U: TMPQR[1].arr.slice(0,4),
        sig: [TMPQR[2].arr[0],0, 0,TMPQR[2].arr[1]],
        V: TMPQR[3].arr.slice(0,4)
    }
}
const polar3qr = function(m) {
    TMPQR[0].arr.set(m);
    polar3(TMPQR[0].p,TMPQR[1].p,TMPQR[2].p);
    return {
        R: TMPQR[1].arr,
        S: TMPQR[2].arr
    }
}
const svd3qr = function(m) {
    TMPQR[0].arr.set(m);
    svd3(TMPQR[0].p,TMPQR[1].p,TMPQR[2].p,TMPQR[3].p);
    return {
        U: TMPQR[1].arr,
        sig: [TMPQR[2].arr[0],0,0, 0,TMPQR[2].arr[1],0, 0,0,TMPQR[2].arr[2]],
        V: TMPQR[3].arr
    }
}
module.exports = {
    svd2qr, polar2qr, svd3qr, polar3qr
}
