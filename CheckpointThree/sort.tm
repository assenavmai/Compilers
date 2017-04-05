* C-Minus Compilation to TM Code
* File: sort.tm
* Standard prelude: 
  0:     LD  6,0(0)	load gp with maxaddress
  1:    LDA  5,0(6)	copy gp to fp
  2:     ST  0,0(0)	clear location 0
* Jump around i/o routines here
* code for input routine
  4:     ST  0,-1(5)	store return
  5:     IN  0,0,0	input
  6:     LD  7,-1(5)	return to caller
* code for output routine
  7:     ST  0,-1(5)	store return
  8:     LD  0,-2(5)	load output value
  9:    OUT  0,0,0	output
 10:     LD  7,-1(5)	return to caller
  3:    LDA  7,7(7) 	jump around i/o code
* End of standard prelude.
* allocating global var: x
* <- vardecl
* processing function: minloc
* jump around function body here
 12:     ST  0,-1(5)	store return
* param
* param
* param
* -> compound statement
* processing local var: i
* processing local var: x
* processing local var: k
* -> assign
* -> id
* looking up id: k
 13:    LDA  0,-9(5)	load id address
* <- id
 14:     ST  0,-8(5)	assign: push left
* -> id
* looking up id: low
 15:     LD  0,-3(5)	load id value
* <- id
 16:     LD  1,-8(5)	assign: load left
 17:     ST  0,0(1)	assign: store value
* <- assign
* -> assign
* -> id
* looking up id: x
 18:    LDA  0,-2(5)	load id address
* <- id
 19:     ST  0,-8(5)	assign: push left
* -> id
* looking up id: a
 20:     LD  0,-2(5)	load id value
* <- id
 21:     LD  1,-8(5)	assign: load left
 22:     ST  0,0(1)	assign: store value
* <- assign
* -> assign
* -> id
* looking up id: i
 23:    LDA  0,-12(5)	load id address
* <- id
 24:     ST  0,-8(5)	assign: push left
* -> op
* -> id
* looking up id: low
 25:     LD  0,-3(5)	load id value
* <- id
 26:     ST  0,-9(5)	op: push left
* -> constant
 27:    LDC  0,1(0)	load const
* <- constant
 28:     LD  1,-9(5)	op: load left
 29:    ADD  0,1,0	op +
* <- op
 30:     LD  1,-8(5)	assign: load left
 31:     ST  0,0(1)	assign: store value
* <- assign
* -> while
* while: jump after body comes back here
* -> op
* -> id
* looking up id: i
 32:     LD  0,-12(5)	load id value
* <- id
 33:     ST  0,-8(5)	op: push left
* -> id
* looking up id: high
 34:     LD  0,-4(5)	load id value
* <- id
 35:     LD  1,-8(5)	op: load left
 36:    SUB  0,1,0	op <
 37:    JLT  0,2(7)	br if true
 38:    LDC  0,0(0)	false case
 39:    LDA  7,1(7)	unconditional jmp
 40:    LDC  0,1(0)	true case
* <- op
* while: jump to end belongs here
* -> compound statement
* -> if
* -> op
* -> id
* looking up id: a
 42:     LD  0,-2(5)	load id value
* <- id
 43:     ST  0,-8(5)	op: push left
* -> id
* looking up id: x
 44:     LD  0,-2(5)	load id value
* <- id
 45:     LD  1,-8(5)	op: load left
 46:    SUB  0,1,0	op <
 47:    JLT  0,2(7)	br if true
 48:    LDC  0,0(0)	false case
 49:    LDA  7,1(7)	unconditional jmp
 50:    LDC  0,1(0)	true case
* <- op
* if: jump to else belongs here
* -> compound statement
* -> assign
* -> id
* looking up id: x
 52:    LDA  0,-2(5)	load id address
* <- id
 53:     ST  0,-8(5)	assign: push left
* -> id
* looking up id: a
 54:     LD  0,-2(5)	load id value
* <- id
 55:     LD  1,-8(5)	assign: load left
 56:     ST  0,0(1)	assign: store value
* <- assign
* -> assign
* -> id
* looking up id: k
 57:    LDA  0,-9(5)	load id address
* <- id
 58:     ST  0,-8(5)	assign: push left
* -> id
* looking up id: i
 59:     LD  0,-12(5)	load id value
* <- id
 60:     LD  1,-8(5)	assign: load left
 61:     ST  0,0(1)	assign: store value
* <- assign
* <- compound statement
* if: jump to end belongs here
 51:    JEQ  0,11(7) 	if: jmp to else
 62:    LDA  7,0(7) 	jmp to end
* <- if
* -> assign
* -> id
* looking up id: i
 63:    LDA  0,-12(5)	load id address
* <- id
 64:     ST  0,-8(5)	assign: push left
* -> op
* -> id
* looking up id: i
 65:     LD  0,-12(5)	load id value
* <- id
 66:     ST  0,-9(5)	op: push left
* -> constant
 67:    LDC  0,1(0)	load const
* <- constant
 68:     LD  1,-9(5)	op: load left
 69:    ADD  0,1,0	op +
* <- op
 70:     LD  1,-8(5)	assign: load left
 71:     ST  0,0(1)	assign: store value
* <- assign
* <- compound statement
 72:    LDA  7,-41(7) 	while: absolute jmp to test
 41:    JEQ  0,31(7) 	while: jmp to end
* <- while
* -> return
* -> id
* looking up id: k
 73:     LD  0,-9(5)	load id value
* <- id
 74:     LD  7,-1(5)	return to caller
* <- return
* <- compound statement
 11:    LDA  7,63(7) 	jump around fn body
* <- fundecl
* processing function: sort
* jump around function body here
 76:     ST  0,-1(5)	store return
* param
* param
* param
* -> compound statement
* processing local var: i
* processing local var: k
* -> assign
* -> id
* looking up id: i
 77:    LDA  0,-12(5)	load id address
* <- id
 78:     ST  0,-13(5)	assign: push left
* -> id
* looking up id: low
 79:     LD  0,-3(5)	load id value
* <- id
 80:     LD  1,-13(5)	assign: load left
 81:     ST  0,0(1)	assign: store value
* <- assign
* -> while
* while: jump after body comes back here
* -> op
* -> id
* looking up id: i
 82:     LD  0,-12(5)	load id value
* <- id
 83:     ST  0,-13(5)	op: push left
* -> op
* -> id
* looking up id: high
 84:     LD  0,-4(5)	load id value
* <- id
 85:     ST  0,-14(5)	op: push left
* -> constant
 86:    LDC  0,1(0)	load const
* <- constant
 87:     LD  1,-14(5)	op: load left
 88:    SUB  0,1,0	op -
* <- op
 89:     LD  1,-13(5)	op: load left
 90:    SUB  0,1,0	op <
 91:    JLT  0,2(7)	br if true
 92:    LDC  0,0(0)	false case
 93:    LDA  7,1(7)	unconditional jmp
 94:    LDC  0,1(0)	true case
* <- op
* while: jump to end belongs here
* -> compound statement
* processing local var: t
* -> assign
* -> id
* looking up id: k
 96:    LDA  0,-9(5)	load id address
* <- id
 97:     ST  0,-14(5)	assign: push left
* -> call of function minloc
* -> id
* looking up id: a
 98:     LD  0,-2(5)	load id value
* <- id
 99:     ST  0,-17(5)	store arg val
* -> id
* looking up id: i
100:     LD  0,-12(5)	load id value
* <- id
101:     ST  0,-18(5)	store arg val
* -> id
* looking up id: high
102:     LD  0,-4(5)	load id value
* <- id
103:     ST  0,-19(5)	store arg val
104:     ST  5,-15(5)	push ofp
105:    LDA  5,-15(5)	push frame
106:    LDA  0,1(7)	load ac with ret ptr
107:    LDA  7,8(7)	jump to fun loc
108:     LD  5,0(5)	pop frame
* <- call
109:     LD  1,-14(5)	assign: load left
110:     ST  0,0(1)	assign: store value
* <- assign
* -> assign
* -> id
* looking up id: t
111:    LDA  0,-10(5)	load id address
* <- id
112:     ST  0,-14(5)	assign: push left
* -> id
* looking up id: a
113:     LD  0,-2(5)	load id value
* <- id
114:     LD  1,-14(5)	assign: load left
115:     ST  0,0(1)	assign: store value
* <- assign
* -> assign
* -> id
* looking up id: a
116:    LDA  0,-2(5)	load id address
* <- id
117:     ST  0,-14(5)	assign: push left
* -> id
* looking up id: a
118:     LD  0,-2(5)	load id value
* <- id
119:     LD  1,-14(5)	assign: load left
120:     ST  0,0(1)	assign: store value
* <- assign
* -> assign
* -> id
* looking up id: a
121:    LDA  0,-2(5)	load id address
* <- id
122:     ST  0,-14(5)	assign: push left
* -> id
* looking up id: t
123:     LD  0,-10(5)	load id value
* <- id
124:     LD  1,-14(5)	assign: load left
125:     ST  0,0(1)	assign: store value
* <- assign
* -> assign
* -> id
* looking up id: i
126:    LDA  0,-12(5)	load id address
* <- id
127:     ST  0,-14(5)	assign: push left
* -> op
* -> id
* looking up id: i
128:     LD  0,-12(5)	load id value
* <- id
129:     ST  0,-15(5)	op: push left
* -> constant
130:    LDC  0,1(0)	load const
* <- constant
131:     LD  1,-15(5)	op: load left
132:    ADD  0,1,0	op +
* <- op
133:     LD  1,-14(5)	assign: load left
134:     ST  0,0(1)	assign: store value
* <- assign
* <- compound statement
135:    LDA  7,-54(7) 	while: absolute jmp to test
 95:    JEQ  0,40(7) 	while: jmp to end
* <- while
* <- compound statement
 75:    LDA  7,60(7) 	jump around fn body
* <- fundecl
* processing function: main
* jump around function body here
137:     ST  0,-1(5)	store return
* -> compound statement
* processing local var: i
* -> assign
* -> id
* looking up id: i
138:    LDA  0,-12(5)	load id address
* <- id
139:     ST  0,-15(5)	assign: push left
* -> constant
140:    LDC  0,0(0)	load const
* <- constant
141:     LD  1,-15(5)	assign: load left
142:     ST  0,0(1)	assign: store value
* <- assign
* -> while
* while: jump after body comes back here
* -> op
* -> id
* looking up id: i
143:     LD  0,-12(5)	load id value
* <- id
144:     ST  0,-15(5)	op: push left
* -> constant
145:    LDC  0,10(0)	load const
* <- constant
146:     LD  1,-15(5)	op: load left
147:    SUB  0,1,0	op <
148:    JLT  0,2(7)	br if true
149:    LDC  0,0(0)	false case
150:    LDA  7,1(7)	unconditional jmp
151:    LDC  0,1(0)	true case
* <- op
* while: jump to end belongs here
* -> compound statement
* -> assign
* -> id
* looking up id: x
153:    LDA  0,-2(5)	load id address
* <- id
154:     ST  0,-15(5)	assign: push left
* -> call of function input
155:     ST  5,-16(5)	push ofp
156:    LDA  5,-16(5)	push frame
157:    LDA  0,1(7)	load ac with ret ptr
158:    LDA  7,-155(7)	jump to fun loc
159:     LD  5,0(5)	pop frame
* <- call
160:     LD  1,-15(5)	assign: load left
161:     ST  0,0(1)	assign: store value
* <- assign
* -> assign
* -> id
* looking up id: i
162:    LDA  0,-12(5)	load id address
* <- id
163:     ST  0,-15(5)	assign: push left
* -> op
* -> id
* looking up id: i
164:     LD  0,-12(5)	load id value
* <- id
165:     ST  0,-16(5)	op: push left
* -> constant
166:    LDC  0,1(0)	load const
* <- constant
167:     LD  1,-16(5)	op: load left
168:    ADD  0,1,0	op +
* <- op
169:     LD  1,-15(5)	assign: load left
170:     ST  0,0(1)	assign: store value
* <- assign
* <- compound statement
171:    LDA  7,-29(7) 	while: absolute jmp to test
152:    JEQ  0,19(7) 	while: jmp to end
* <- while
* -> call of function sort
* -> id
* looking up id: x
172:     LD  0,-2(5)	load id value
* <- id
173:     ST  0,-17(5)	store arg val
* -> constant
174:    LDC  0,0(0)	load const
* <- constant
175:     ST  0,-18(5)	store arg val
* -> constant
176:    LDC  0,10(0)	load const
* <- constant
177:     ST  0,-19(5)	store arg val
178:     ST  5,-15(5)	push ofp
179:    LDA  5,-15(5)	push frame
180:    LDA  0,1(7)	load ac with ret ptr
181:    LDA  7,11(7)	jump to fun loc
182:     LD  5,0(5)	pop frame
* <- call
* -> assign
* -> id
* looking up id: i
183:    LDA  0,-12(5)	load id address
* <- id
184:     ST  0,-15(5)	assign: push left
* -> constant
185:    LDC  0,0(0)	load const
* <- constant
186:     LD  1,-15(5)	assign: load left
187:     ST  0,0(1)	assign: store value
* <- assign
* -> while
* while: jump after body comes back here
* -> op
* -> id
* looking up id: i
188:     LD  0,-12(5)	load id value
* <- id
189:     ST  0,-15(5)	op: push left
* -> constant
190:    LDC  0,10(0)	load const
* <- constant
191:     LD  1,-15(5)	op: load left
192:    SUB  0,1,0	op <
193:    JLT  0,2(7)	br if true
194:    LDC  0,0(0)	false case
195:    LDA  7,1(7)	unconditional jmp
196:    LDC  0,1(0)	true case
* <- op
* while: jump to end belongs here
* -> compound statement
* -> call of function x
* -> id
* looking up id: x
198:     LD  0,-2(5)	load id value
* <- id
199:     ST  0,-17(5)	store arg val
200:     ST  5,-15(5)	push ofp
201:    LDA  5,-15(5)	push frame
202:    LDA  0,1(7)	load ac with ret ptr
203:    LDA  7,1(7)	jump to fun loc
204:     LD  5,0(5)	pop frame
* <- call
* -> assign
* -> id
* looking up id: i
205:    LDA  0,-12(5)	load id address
* <- id
206:     ST  0,-15(5)	assign: push left
* -> op
* -> id
* looking up id: i
207:     LD  0,-12(5)	load id value
* <- id
208:     ST  0,-16(5)	op: push left
* -> constant
209:    LDC  0,1(0)	load const
* <- constant
210:     LD  1,-16(5)	op: load left
211:    ADD  0,1,0	op +
* <- op
212:     LD  1,-15(5)	assign: load left
213:     ST  0,0(1)	assign: store value
* <- assign
* <- compound statement
214:    LDA  7,-27(7) 	while: absolute jmp to test
197:    JEQ  0,17(7) 	while: jmp to end
* <- while
* <- compound statement
136:    LDA  7,78(7) 	jump around fn body
* <- fundecl
215:     ST  5,-13(5)	push ofp
216:    LDA  5,-13(5)	push frame
217:    LDA  0,1(7)	load ac with ret ptr
218:    LDA  7,-82(7) 	jump to main loc
219:     LD  5,0(5)	pop frame
* End of execution.
220:   HALT  0,0,0	
