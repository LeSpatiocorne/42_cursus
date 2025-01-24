#!/bin/bash
if [ $# -ne 1 ]; then
    echo "Usage: $0 <server_pid>"
    exit 1
fi

if [ -f "./client_bonus" ]; then
    CLIENT="../client_bonus"
elif [ -f "../client" ]; then
    CLIENT="../client"
else
    echo "Error: Neither client nor client_bonus executable found"
    exit 1
fi

$CLIENT $1 "😀 😎 🤖 💻 🚀"
$CLIENT $1 "Hello 你好 안녕하세요 こんにちは Привет مرحبا"
$CLIENT $1 "♠ ♣ ♥ ♦ ★ ☆ ☮ ☯"
$CLIENT $1 "π ∑ ∞ ∆ √ ∫ ≠ ≈"
$CLIENT $1 "$ € ¥ £ ¢ ₿"
$CLIENT $1 "©®™℃℉♪♫"
