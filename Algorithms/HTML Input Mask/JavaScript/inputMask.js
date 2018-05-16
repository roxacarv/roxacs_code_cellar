//the mask receives a value such as ####-#### where # will be ignored and any special symbol left such as -
//will be added to the html value
//each # count for a letter (or digit) before the special symbol being concatenated to the input value
function inputMask(htmlInput, mask) {
    var lenghtOfInput = htmlInput.value.length;
    var output = mask.substring(1, 0);
    var text = mask.substring(lenghtOfInput);
    if (text.substring(0, 1) !== output) {
        htmlInput.value += text.substring(0, 1); //add the special symbol to the value of the html input
    }
}