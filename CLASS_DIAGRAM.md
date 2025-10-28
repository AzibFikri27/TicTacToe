╔════════════════════════════════════════════════════════════════════════╗
║              TIC-TAC-TOE CLASS HIERARCHY DIAGRAM                       ║
╚════════════════════════════════════════════════════════════════════════╝

┌─────────────────────────────────────────────────────────────────────┐
│                         SHAPE HIERARCHY                              │
└─────────────────────────────────────────────────────────────────────┘

                           ┌──────────────┐
                           │    Shape     │ (Abstract Base Class)
                           │  (abstract)  │
                           ├──────────────┤
                           │ - x: int     │
                           │ - y: int     │
                           │ - color: int │
                           ├──────────────┤
                           │ + getX()     │
                           │ + setX()     │
                           │ + draw()=0   │ ← Pure virtual
                           └──────┬───────┘
                                  │
                      ┌───────────┴───────────┐
                      │                       │
                ┌─────▼──────┐         ┌─────▼──────┐
                │   Cross    │         │   Circle   │
                ├────────────┤         ├────────────┤
                │ - size:int │         │ - radius   │
                ├────────────┤         ├────────────┤
                │ + draw()   │         │ + draw()   │
                └────────────┘         └────────────┘

┌─────────────────────────────────────────────────────────────────────┐
│                        PLAYER HIERARCHY                              │
└─────────────────────────────────────────────────────────────────────┘

                         ┌────────────────┐
                         │     Player     │ (Abstract Base Class)
                         │   (abstract)   │
                         ├────────────────┤
                         │ - mark: char   │
                         │ - score: int   │
                         ├────────────────┤
                         │ + getMark()    │
                         │ + getMove()=0  │ ← Pure virtual
                         └────────┬───────┘
                                  │
                     ┌────────────┴────────────┐
                     │                         │
              ┌──────▼────────┐      ┌────────▼────────┐
              │ HumanPlayer   │      │ ComputerPlayer  │
              ├───────────────┤      ├─────────────────┤
              │               │      │                 │
              ├───────────────┤      ├─────────────────┤
              │ + getMove()   │      │ + getMove()     │
              └───────────────┘      │ + getBestMove() │
                                     │ + findWinning() │
                                     └─────────────────┘

┌─────────────────────────────────────────────────────────────────────┐
│                    COMPOSITION & AGGREGATION                         │
└─────────────────────────────────────────────────────────────────────┘

                    ┌──────────────┐
                    │     Cell     │
                    ├──────────────┤
                    │ - row: int   │
                    │ - col: int   │
                    │ - mark: char │
                    │ - shape: *   │ ◆─────┐ COMPOSITION
                    ├──────────────┤       │ (Cell owns Shape)
                    │ + isEmpty()  │       │
                    │ + setShape() │       │
                    └──────────────┘       │
                                           │
                           ┌───────────────▼──┐
                           │      Shape       │
                           └──────────────────┘

                    ┌──────────────┐
                    │    Board     │
                    ├──────────────┤
                    │ - cells[9]   │ ◇─────┐ AGGREGATION
                    ├──────────────┤       │ (Board has Cells)
                    │ + drawGrid() │       │
                    │ + checkWin() │       │
                    └──────────────┘       │
                                           │
                           ┌───────────────▼──┐
                           │      Cell        │
                           └──────────────────┘

                    ┌──────────────┐
                    │     Game     │
                    ├──────────────┤
                    │ - board: *   │ ◇─────┐ AGGREGATION
                    │ - player1: * │ ◇──┐  │ (Game uses these)
                    │ - player2: * │ ◇──┼──┤
                    ├──────────────┤    │  │
                    │ + run()      │    │  │
                    │ + render()   │    │  │
                    └──────────────┘    │  │
                                        │  │
                    ┌───────────────────▼──▼──┐
                    │  Board      Player      │
                    └─────────────────────────┘

┌─────────────────────────────────────────────────────────────────────┐
│                        RELATIONSHIPS                                 │
└─────────────────────────────────────────────────────────────────────┘

  ─────▶   Inheritance (IS-A relationship)
  ◆─────   Composition (Strong ownership - OWNS-A)
  ◇─────   Aggregation (Weak ownership - HAS-A)

┌─────────────────────────────────────────────────────────────────────┐
│                     KEY OOP CONCEPTS                                 │
└─────────────────────────────────────────────────────────────────────┘

1. ENCAPSULATION
   • All data members are private
   • Access through public getters/setters

2. INHERITANCE
   • Shape → Cross, Circle
   • Player → HumanPlayer, ComputerPlayer

3. POLYMORPHISM
   • Virtual draw() in Shape hierarchy
   • Virtual getMove() in Player hierarchy

4. COMPOSITION
   • Cell owns Shape (strong ownership)

5. AGGREGATION
   • Game uses Board and Players
   • Board uses Cells

6. ARRAY OF OBJECTS
   • Board contains Cell cells[9]
