# QuantumDifferentialAttack
Source code for Differential Characteristics Search using Quantum Computing (https://eprint.iacr.org/2022/489.pdf)

## Source Code 
### There are three files in this source code.
* _PermutationToSwap.py_
* _QuantumDifferentialCharacteristicsSearch.ipynb_
* _smallGIFT_DiffSearch_Branch_and_Bound.c_


## Equivalent Swap Operations for a given Bit Permutation
* _PermutationToSwap.py_ contains the source code to find equivalent swap operations corresponding to a given bit permutation. The permutation can be specified in the ```Permutation``` variable of the source code. These swap operations can be performed using swap gates on a quantum computer/simulator.
* _PermutationToSwap.py_ contains the GIFT-64 permutation and 8-bit permutation of smallGIFT(commented). 
* The source code can be executed using the following command:\
```python PermutationToSwap.py```
* The output of the execution is a list of swap operations. \
``` For smallGIFT: [(1, 3), (1, 7), (2, 5), (2, 4)] ```\
``` For GIFT-64: [(1, 17), (1, 21), (1, 5), (2, 34), (2, 42), (2, 10), (3, 51), (3, 63), (3, 15), (4, 48), (4, 12), (4, 16), (6, 18), (6, 38), (6, 26), (7, 35), (7, 59), (7, 31), (8, 32), (9, 49), (9, 29), (9, 37), (11, 19), (11, 55), (11, 47), (13, 33), (13, 25), (13, 53), (14, 50), (14, 46), (14, 58), (20, 52), (20, 60), (20, 28), (23, 39), (23, 43), (23, 27), (24, 36), (24, 56), (24, 44), (30, 54), (41, 57), (41, 61), (41, 45)] ```

## Quantum Differential Characteristics Search
* _QuantumDifferentialCharacteristicsSearch.ipynb_ is python notebook. The notebook contains source code to generate quantum circuit for S-box, Permutation, Encryption Algorithm, Decryption Algorithm and Quantum Differential Characteristic Search. The generated quantum circuits are also provided in the notebook.
* The notebook contains experiment to search differential characteristic for three rounds of smallGIFT using qasm simulator. Results(list of probability distribution of output differences for input difference 0x01) of five experiments are also provided and the format of results is as follows:
```{41: 0.0123, 9: 0.011, 86: 0.0105, 127: 0.01, 95: 0.0097, 33: 0.0091, 76: 0.008, 11: 0.0078, 48: 0.0078, 119: 0.0078, 74: 0.0071, 75: 0.007, 195: 0.0069, 98: 0.0067, 107: 0.0067, 30: 0.0065, 114: 0.0065, 24: 0.0064, 34: 0.0064, 8: 0.0063, 163: 0.0062, 54: 0.0061, 94: 0.0061, 112: 0.006, 215: 0.006, 14: 0.0059, 43: 0.0059, 50: 0.0059, 118: 0.0059, 129: 0.0059, 26: 0.0058, 10: 0.0057, 79: 0.0057, 90: 0.0057, 151: 0.0057, 25: 0.0056, 63: 0.0056, 100: 0.0056, 102: 0.0056, 204: 0.0056, 222: 0.0056, 57: 0.0055, 82: 0.0055, 158: 0.0055, 200: 0.0055, 247: 0.0055, 92: 0.0054, 96: 0.0054, 31: 0.0053, 35: 0.0053, 38: 0.0053, 78: 0.0053, 17: 0.0052, 88: 0.0052, 131: 0.0052, 234: 0.0052, 23: 0.0051, 71: 0.0051, 93: 0.0051, 77: 0.005, 109: 0.005, 159: 0.005, 171: 0.005, 12: 0.0049, 28: 0.0048, 202: 0.0048, 15: 0.0047, 16: 0.0047, 36: 0.0047, 49: 0.0047, 73: 0.0047, 254: 0.0047, 70: 0.0046, 72: 0.0046, 147: 0.0046, 170: 0.0046, 243: 0.0046, 27: 0.0045, 47: 0.0045, 55: 0.0045, 59: 0.0045, 103: 0.0045, 111: 0.0045, 150: 0.0045, 167: 0.0045, 173: 0.0045, 193: 0.0045, 64: 0.0044, 83: 0.0044, 152: 0.0044, 153: 0.0044, 3: 0.0043, 116: 0.0043, 139: 0.0043, 184: 0.0043, 211: 0.0043, 236: 0.0043, 5: 0.0042, 13: 0.0042, 143: 0.0042, 145: 0.0042, 183: 0.0042, 185: 0.0042, 201: 0.0042, 87: 0.0041, 115: 0.0041, 172: 0.0041, 186: 0.0041, 227: 0.0041, 249: 0.0041, 39: 0.004, 67: 0.004, 68: 0.004, 69: 0.004, 138: 0.004, 203: 0.004, 231: 0.004, 233: 0.004, 52: 0.0039, 91: 0.0039, 99: 0.0039, 154: 0.0039, 190: 0.0039, 206: 0.0039, 218: 0.0039, 255: 0.0039, 161: 0.0038, 177: 0.0038, 225: 0.0038, 66: 0.0037, 105: 0.0037, 142: 0.0037, 197: 0.0037, 199: 0.0037, 216: 0.0037, 223: 0.0037, 235: 0.0037, 251: 0.0037, 19: 0.0036, 135: 0.0036, 140: 0.0036, 141: 0.0036, 174: 0.0036, 176: 0.0036, 182: 0.0036, 219: 0.0036, 229: 0.0036, 155: 0.0035, 165: 0.0035, 192: 0.0035, 232: 0.0035, 248: 0.0035, 85: 0.0034, 97: 0.0034, 101: 0.0034, 123: 0.0034, 125: 0.0034, 179: 0.0034, 187: 0.0034, 250: 0.0034, 45: 0.0033, 65: 0.0033, 89: 0.0033, 126: 0.0033, 178: 0.0033, 220: 0.0033, 226: 0.0033, 238: 0.0033, 246: 0.0033, 136: 0.0032, 198: 0.0032, 237: 0.0032, 2: 0.0031, 37: 0.0031, 62: 0.0031, 121: 0.0031, 149: 0.0031, 205: 0.0031, 224: 0.0031, 21: 0.003, 51: 0.003, 56: 0.003, 104: 0.003, 106: 0.0029, 132: 0.0029, 207: 0.0029, 7: 0.0028, 32: 0.0028, 42: 0.0028, 133: 0.0028, 191: 0.0028, 239: 0.0028, 22: 0.0026, 144: 0.0026, 146: 0.0026, 188: 0.0026, 210: 0.0026, 156: 0.0025, 168: 0.0025, 194: 0.0025, 209: 0.0025, 221: 0.0025, 252: 0.0025, 81: 0.0024, 175: 0.0024, 180: 0.0024, 217: 0.0024, 241: 0.0024, 162: 0.0023, 242: 0.0023, 113: 0.0022, 148: 0.0022, 166: 0.0022, 181: 0.0022, 253: 0.0022, 29: 0.0021, 110: 0.0021, 134: 0.0021, 157: 0.0021, 169: 0.0021, 245: 0.0021, 53: 0.002, 130: 0.002, 214: 0.002, 46: 0.0019, 189: 0.0019, 208: 0.0019, 213: 0.0019, 18: 0.0018, 164: 0.0018, 196: 0.0018, 44: 0.0017, 122: 0.0017, 230: 0.0017, 228: 0.0016, 4: 0.0015, 61: 0.0015, 244: 0.0015, 240: 0.0014, 58: 0.0012, 108: 0.0011, 137: 0.0011, 1: 0.001, 212: 0.001, 6: 0.0009, 117: 0.0009, 160: 0.0009, 120: 0.0008, 60: 0.0005, 124: 0.0005, 128: 0.0005}```
* A sample experiment to explore all input differences for 1-round of smallGIFT is also provided. The number of round is reduced to 1 and the shots are reduced to 100 due to resource contraints. Based on the availability of resources these parameters can be adjusted to get accuracte results.
* The notebook can be executed on Google Colab(https://colab.research.google.com/) platform. Qiskit and other dependencies can be easily installed on Colab(using first cell of the notebook). Colab also provides support for GPU which makes the execution faster. 

## Validaton of Results using Branch-and-bound Approach
* _smallGIFT_DiffSearch_Branch_and_Bound.c_ is used to validate results of quantum differential characteristics for 3 rounds of smallGIFT. The c file implementes differential characteristics search for 3 round of smallGIFT using branch-and-bound approach. 
* The source file can be compiled and executed using following commnds (on Linux):\
```g++ smallGIFT_DiffSearch_Branch_and_Bound.c -o smallGIFTDiffSearchBB```\
```./smallGIFTDiffSearchBB```
* The output of the execution is in following format:\
```1: 0.001221, 2: 0.003906, 3: 0.004883, 4: 0.001953, 5: 0.003662, 6: 0.000977, 7: 0.003418, 8: 0.005859, 9: 0.009827, 10: 0.007141, 11: 0.006573, 12: 0.004883, 13: 0.003929, 14: 0.005432, 15: 0.005161, 16: 0.005859, 17: 0.004761, 18: 0.000977, 19: 0.004395, 20: 0.000000, 21: 0.002940, 22: 0.001953, 23: 0.005371, 24: 0.005981, 25: 0.005032, 26: 0.005798, 27: 0.004666, 28: 0.004469, 29: 0.002400, 30: 0.006104, 31: 0.005459, 32: 0.002441, 33: 0.008545, 34: 0.007202, 35: 0.005066, 36: 0.005371, 37: 0.002930, 38: 0.005127, 39: 0.003357, 40: 0.000000, 41: 0.013795, 42: 0.002808, 43: 0.006573, 44: 0.001709, 45: 0.003929, 46: 0.001831, 47: 0.004666, 48: 0.006836, 49: 0.003662, 50: 0.006592, 51: 0.003479, 52: 0.005270, 53: 0.001651, 54: 0.007202, 55: 0.003662, 56: 0.002441, 57: 0.005032, 58: 0.002075, 59: 0.004666, 60: 0.000610, 61: 0.001904, 62: 0.002930, 63: 0.005459, 64: 0.003906, 65: 0.004639, 66: 0.003906, 67: 0.004883, 68: 0.003906, 69: 0.003906, 70: 0.004883, 71: 0.004150, 72: 0.005493, 73: 0.004540, 74: 0.007141, 75: 0.006573, 76: 0.006470, 77: 0.006394, 78: 0.005920, 79: 0.005161, 80: 0.000000, 81: 0.003296, 82: 0.004883, 83: 0.003662, 84: 0.000000, 85: 0.002692, 86: 0.009766, 87: 0.004639, 88: 0.005127, 89: 0.003811, 90: 0.005310, 91: 0.004177, 92: 0.005089, 93: 0.003903, 94: 0.007568, 95: 0.008908, 96: 0.006592, 97: 0.003052, 98: 0.007202, 99: 0.005066, 100: 0.005859, 101: 0.003784, 102: 0.006104, 103: 0.003357, 104: 0.002197, 105: 0.004540, 106: 0.002808, 107: 0.006573, 108: 0.002197, 109: 0.005402, 110: 0.002075, 111: 0.004666, 112: 0.005371, 113: 0.003296, 114: 0.005615, 115: 0.003479, 116: 0.004774, 117: 0.001527, 118: 0.006226, 119: 0.006592, 120: 0.001465, 121: 0.003811, 122: 0.001831, 123: 0.004177, 124: 0.000610, 125: 0.002400, 126: 0.003662, 127: 0.008908, 128: 0.000732, 129: 0.004883, 130: 0.002930, 131: 0.004944, 132: 0.002197, 133: 0.003296, 134: 0.002014, 135: 0.003418, 136: 0.002686, 137: 0.001709, 138: 0.004944, 139: 0.004150, 140: 0.003296, 141: 0.003418, 142: 0.003662, 143: 0.003418, 144: 0.003296, 145: 0.003906, 146: 0.002869, 147: 0.003906, 148: 0.001716, 149: 0.002386, 150: 0.003723, 151: 0.004578, 152: 0.004517, 153: 0.004028, 154: 0.003906, 155: 0.003662, 156: 0.002387, 157: 0.002450, 158: 0.004578, 159: 0.004395, 160: 0.000732, 161: 0.004883, 162: 0.002930, 163: 0.005005, 164: 0.002197, 165: 0.003296, 166: 0.002014, 167: 0.003357, 168: 0.003174, 169: 0.002197, 170: 0.005005, 171: 0.004150, 172: 0.003296, 173: 0.003418, 174: 0.003601, 175: 0.003296, 176: 0.003296, 177: 0.004517, 178: 0.002869, 179: 0.003967, 180: 0.001716, 181: 0.002205, 182: 0.003723, 183: 0.004456, 184: 0.003906, 185: 0.004272, 186: 0.003967, 187: 0.003784, 188: 0.002692, 189: 0.002452, 190: 0.004456, 191: 0.004272, 192: 0.002930, 193: 0.003540, 194: 0.002930, 195: 0.004944, 196: 0.002319, 197: 0.003906, 198: 0.002502, 199: 0.003784, 200: 0.004272, 201: 0.004150, 202: 0.004944, 203: 0.004150, 204: 0.004395, 205: 0.003418, 206: 0.004028, 207: 0.003418, 208: 0.001953, 209: 0.003540, 210: 0.002380, 211: 0.003540, 212: 0.001344, 213: 0.002262, 214: 0.003235, 215: 0.005676, 216: 0.002930, 217: 0.002808, 218: 0.003540, 219: 0.003174, 220: 0.002759, 221: 0.002450, 222: 0.005676, 223: 0.003906, 224: 0.002930, 225: 0.004150, 226: 0.002930, 227: 0.005005, 228: 0.002319, 229: 0.003784, 230: 0.002502, 231: 0.003723, 232: 0.003418, 233: 0.004150, 234: 0.005005, 235: 0.004150, 236: 0.004272, 237: 0.003174, 238: 0.003967, 239: 0.003296, 240: 0.001953, 241: 0.003052, 242: 0.002380, 243: 0.003601, 244: 0.001344, 245: 0.001957, 246: 0.003235, 247: 0.005554, 248: 0.003662, 249: 0.002808, 250: 0.003601, 251: 0.003296, 252: 0.002940, 253: 0.002204, 254: 0.005554, 255: 0.003784```
* It can be observed that most of the high probability output differences are same in both the approaches. Zero probability (impossible) output differences are also same in both the approaches.
