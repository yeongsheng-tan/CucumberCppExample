Feature: Basic Operations
  Scenario Outline: Perform some of the basic operations
  Given the input "<input>"
  When the calculator performs "<operator>"
  Then the result should be "<output>"
  Examples:
  | input | operator      | output  |
  | 30 4  | +             | 34      |
  | 30 4  | -             | 26      |
  | 5     | !             | 120     |
  | 4 6   | *             | 24      |
  | 8 2   | /             | 4       |
  | 1     | -             | -1      |
  |       | +             | 0       |
  | 8 0   | /             | <error> |
  |       | $%^unknown*&^ | <error> |