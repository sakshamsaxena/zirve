# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What This Is

A personal portfolio website (sakshamsaxena.in) built as a terminal/shell emulator UI. Users interact with a command prompt to browse personal info. Built with React 16, Webpack 4, and Babel 7.

## Commands

- `npm start` — dev server with hot reload (serves from `public/`, bundle at `/dist/`)
- `npm run build` — development build to `dist/bundle.js`
- `npm run release` — production build to `dist/bundle.js`
- `bash release.sh` — production build + deploy: builds bundle, clones master branch into a temp dir, copies `dist/bundle.js` over, commits as `[AUTO-UPDATE] Update App`, and pushes. GitHub Pages serves master.

## Branch Strategy

- **`v2`** — development branch (React source code lives here)
- **`master`** — deploy branch (only `index.html`, `dist/bundle.js`, and static assets). Never edit directly; `release.sh` pushes built artifacts here. GitHub Pages serves this branch at `sakshamsaxena.in`.

## Architecture

Terminal emulator pattern: the app renders a prompt, accepts text input, parses it as a command, and appends output to a scrolling buffer.

**Component hierarchy:** `App` → `Buffer` (command history display) + `Prompt` (text input). App is a class component holding all state (`buffers` array). Buffer and Prompt are functional/presentational.

**Command system (`src/types/command/`):**
1. User hits Enter → `App.checkPromptForCommand()`
2. `InputSanitizer` (`src/logic/sanitizer.js`) validates input (alpha + hyphens only) and splits into command name + args
3. `Command` class (`src/types/command/index.js`) routes to the matching command module in `src/types/command/commands/`
4. Each command exposes `getInput()` and `getOutput()` (returns JSX)
5. Result is pushed to the buffer array and rendered

**Available commands:** `init` (welcome/links), `whoami` (name display), `tree` (education/experience/achievements from `src/types/directory/`), `anniversary` (ASCII art)

**To add a new command:** create a new file in `src/types/command/commands/`, export a class with `getInput()` and `getOutput()` methods, then register it in `src/types/command/index.js`.

## Styling

CSS is bundled via webpack style-loader (no CSS modules). Terminal aesthetic: black background, green monospace text (`Courier New`). Mobile breakpoint at 768px (width goes from 50% to 90%).
