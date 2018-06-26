const fs = require('fs');
const path = require('path');

const filenames = fs.readdirSync(path.join(__dirname, './src'));
console.log(filenames);

const formatDate = (ts) => {
    const date = new Date(ts);
    return date.getFullYear() + '-' + (date.getMonth()+1) + '-' + date.getDate();
}

let ts = new Date(2016, 0, 1).getTime();

fs.mkdirSync(path.resolve(__dirname, './files'));

filenames.forEach(filename => {
    const code = filename.split('.')[0];
    const data = 
`---
layout: post
title:  "${code} - "
categories: []
code: ${code}
src: ${filename}
---`;
    const name = formatDate(ts) + '-' + code + '.md';
    fs.writeFileSync(
        path.resolve(__dirname, './files', name), 
        data, 'utf8'
    );
    ts += 1000 * 60 * 60 * 24;
});