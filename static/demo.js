var Module = {
    preRun: [],
    postRun: [],
    print: (function () {
        var element = document.getElementById('output');
        //if (element) element.value = ''; // clear browser cache
        return function (text) {
            if (arguments.length > 1) text = Array.prototype.slice.call(arguments).join(' ');
            console.log(text);
            if (element) {
                if (text) element.value = text + "\n";
                element.scrollTop = element.scrollHeight; // focus on bottom
            }

        };
    })()
};
function loadHelloWorld() {
    document.getElementById("bf-code").value = "# Hello World Program\n>++++++++[<+++++++++>-]<.>++++[<+++++++>-]<+.+++++++..+++.>>++++++[<+++++++>-]<++.------------.> ++++++[< +++++++++> -] < +.<.++ +.------.--------.>>> ++++[< ++++++++> -] < +.";
}
window.addEventListener("load", loadHelloWorld);
document.getElementById("file-load").addEventListener('click', () => {
    var reader = new FileReader();
    reader.addEventListener('load', () => {
        document.getElementById("bf-code").value = reader.result;
    })
    reader.readAsText(document.getElementById("file-input").files[0]);
})
document.getElementById("reset-button").addEventListener("click", () => { window.location.reload() });
document.getElementById("run_BF").addEventListener("click", () => {
    var bf_code = document.getElementById("bf-code").value;
    const result = Module.ccall(
        "brainfuck", // name of C function
        null, // return type
        ['string', 'string'], // argument types
        [bf_code, ''] // arguments
    );
});
