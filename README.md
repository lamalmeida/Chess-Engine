# Chess Engine

A C++ chess engine project built around bitboards and precomputed attack tables.

The board implementation includes piece bitboards, occupancy maps, move generation, attack detection, promotions, castling state, and magic-bitboard lookup tables for sliding-piece attacks.

## Build

Requires a C++11-compatible compiler and `make`.

```bash
make
./chess
```

Clean generated build artifacts with:

```bash
make clean
```

## Status

This is a work in progress. Threefold-repetition handling is not currently implemented.
