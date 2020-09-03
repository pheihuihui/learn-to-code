import { app, BrowserWindow, Menu, MenuItem, dialog } from 'electron';
import * as path from 'path';
const addon = require('../build/Release/addon')
const hello = addon.hello() as string

if (require('electron-squirrel-startup')) {
  app.quit();
}

const createWindow = (): void => {
  const mainWindow = new BrowserWindow({
    height: 600,
    width: 800,
  });
  mainWindow.loadFile(path.join(__dirname, '../src/index.html'));
  dialog.showErrorBox('title', hello)
};

app.on('ready', createWindow);

app.on('window-all-closed', () => {
  if (process.platform !== 'darwin') {
    app.quit();
  }
});

app.on('activate', () => {
  if (BrowserWindow.getAllWindows().length === 0) {
    createWindow();
  }
});
