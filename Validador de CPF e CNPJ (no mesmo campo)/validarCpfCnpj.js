function cpfCnpjMask(t) {
    var i = t.value.length;
    var mask = "";
    if(i < 14) {
        mask = "###.###.###-##";
    } else {
        mask = "##.###.###/####-##";
    }
     
    if(i == 15) {
        var k = t.value.replace(/\D/g, '');
        t.value = k.substring(0, 2) + "." + k.substring(2, 5) + "." + k.substring(5, 8) + "/" + k.substring(8, 12);
    }
    
    var output = mask.substring(1, 0);
    var text = mask.substring(i);
    if (text.substring(0, 1) !== output) {
        t.value += text.substring(0, 1);
    }
    if(i == 18) {
        validateCnpj(t);
    } else if(i == 14) {
        validateCpf(t);
    }
    
}

// Função para validar o CNPJ
function validateCnpj(t) {
    
    var cnpjNumber = t.value.replace(/\D/g, '');
    var firstTwelveDigits = cnpjNumber.substring(0, 12);
    var firstThirteenDigits = cnpjNumber.substring(0, 13);
    var firstDigit = cnpjNumber.substring(12, 13);
    var secondDigit = cnpjNumber.substring(13, 14);
    var firstVerifiers = [5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2];
    var secondVerifiers = [6, 5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2];
    
    var validateFirstDigit = 0;
    var validateSecondDigit = 0;
    
    for(var i = 0; i < 12; i++) {
        validateFirstDigit += firstTwelveDigits.charAt(i) * firstVerifiers[i];
    }
    
    validateFirstDigit = validateFirstDigit % 11;
    
    if(validateFirstDigit < 2) {
        validateFirstDigit = 0;
    } else {
        validateFirstDigit = 11 - validateFirstDigit;
    }
    
    for(var j = 0; j < 13; j++) {
        validateSecondDigit += firstThirteenDigits.charAt(i) * secondVerifiers[i];
    }
    
    validateSecondDigit = validateSecondDigit % 11;
    
    if(validateSecondDigit < 2) {
        validateSecondDigit = 0;
    } else {
        validateSecondDigit = 11 - validateSecondDigit;
    }
    
    if(validateFirstDigit == firstDigit && validateSecondDigit == secondDigit) {
        console.log("CNPJ valido");
    } else {
        console.log("CNPJ invalido");
    }
    
    
}

// Função valida o CPF
function validateCpf(t) {
    
    var cpfNumber = t.value.replace(/\D/g, '');
    var firstNineDigits = cpfNumber.substring(0, 9);
    var firstTenDigits = cpfNumber.substring(0, 10);
    var firstDigit = cpfNumber.substring(9, 10);
    var secondDigit = cpfNumber.substring(10, 11);
    
    var validateFirstDigit = 0;
    var validateSecondDigit = 0;
    
    for(var i = 0; i < 9; i++) {
        validateFirstDigit += firstNineDigits.charAt(i) * ((firstNineDigits.length + 1) - i);
    }
    
    validateFirstDigit = (validateFirstDigit * 10) % 11;
    
    if(validateFirstDigit == 10) {
        validateFirstDigit = 0;
    }
    
    for(var j = 0; j < 10; j++) {
        validateSecondDigit += firstTenDigits.charAt(j) * ((firstTenDigits.length + 1) - j);
    }
    
    validateSecondDigit = (validateSecondDigit * 10) % 11;
    
    if(validateSecondDigit == 10) {
        validateSecondDigit = 0;
    }
    
    if(validateFirstDigit == firstDigit && validateSecondDigit == secondDigit) {
        console.log("CPF valido");
    } else {
        console.log("CPF invalido");
    }
    
}