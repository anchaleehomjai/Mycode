function hello(){
    const number = prompt('input number  ')
    let n = 2 
    alert("Hi " + number)
    console.log(number)
    console.log(`My name is ${name.substring(2)}~`)
}
const numbers = [1, 2, 3,4,5];

function ten(numbers) {
    return numbers.map(x => x * 10);
}
function index(num) {
    let i = 0

    return num.map(x => x + 10);
}

console.log(doubleNumbers(numbers));
console.log(doubleNumbers(num));

document.getElementById("btn")
.addEventListener('click',hello)