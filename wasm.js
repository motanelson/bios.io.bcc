const fs = require('fs');

console.clear();
console.log('\x1bc\x1b[43m\x1b[30m\nCriando ficheiro main.wasm...\n\x1b[0m');

// Função auxiliar para escrever bytes em ficheiro
function writeBytes(...bytes) {
  buffer.push(...bytes);
}

const buffer = [];

// Cabeçalho
writeBytes(0x00, ...Buffer.from('asm'));     // \0asm
writeBytes(0x01, 0x00, 0x00, 0x00);          // version 1

// Seção de tipos (type)
writeBytes(0x01, 0x07);                      // section id, size
writeBytes(0x01, 0x60, 0x02, 0x7f, 0x7f);    // 1 func type: (i32, i32)
writeBytes(0x01, 0x7f);                      // return i32

// Seção de funções
writeBytes(0x03, 0x02, 0x01, 0x00);          // section id 3, size 2, 1 func, type 0

// Seção de exportações
writeBytes(0x07, 0x07, 0x01, 0x03);          // section id 7, size 7, 1 export, name len 3
buffer.push(...Buffer.from('sum'));         // "sum"
writeBytes(0x00, 0x00);                      // export kind func, index 0

// Seção de código
writeBytes(0x0A, 0x09, 0x01, 0x07, 0x00);    // code section: id 10, size 9, 1 func, body size 7, no locals
writeBytes(0x20, 0x00, 0x20, 0x01, 0x6A, 0x0B); // get_local 0, get_local 1, i32.add, end

// Gravar no ficheiro
fs.writeFileSync('main.wasm', Buffer.from(buffer));

console.log('Ficheiro main.wasm criado com sucesso!');

