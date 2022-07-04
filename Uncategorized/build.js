const esbuild = require('esbuild')
const showdown = require('showdown')
const fs = require('fs')

esbuild.buildSync({
    entryPoints: ['./src/index.ts'],
    outfile: './dist/bundle.js',
    tsconfig: 'tsconfig.json',
    bundle: true,
    define: { 'process.env.NODE_ENV': '"production"' },
    minify: true,
    treeShaking: true
})

// esbuild.buildSync({
//     entryPoints: ['./src/worker.ts'],
//     treeShaking: 'ignore-annotations',
//     outfile: './dist/worker.js',
//     tsconfig: 'tsconfig.json',
//     bundle: true,
//     define: { 'process.env.NODE_ENV': '"production"' },
//     minify: false
// })

// fse.copy('./src/pages/index.html', './dist/index.html')
//     .then(() => console.log('copy html success!'))
//     .catch(err => console.error(err))

// fse.copy('./src/pages/cube.ico', './dist/favicon.ico')
//     .then(() => console.log('copy icon success!'))
//     .catch(err => console.error(err))


let converter = new showdown.Converter()
let text = '# hello, markdown!'
let html = converter.makeHtml(text)
fs.writeFileSync('./dist/page1.html', html)