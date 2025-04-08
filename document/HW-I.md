# Turing Complete: XOR GATE


¬(¬(¬(p∧q)∧p)∧¬(¬(p∧q)∧q)) = ¬((¬p∧¬q)∨(p∧q)) 

¬(¬(¬(p∧q)∧p)∧¬(¬(p∧q)∧q))   =    (¬(p∧q)∧p)∨(¬(p∧q)∧q)   regel 9
(¬(p∧q)∧p)∨(¬(p∧q)∧q)   =   ((¬p∨¬q)∧p)∨((¬p∨¬q)∧q)   regel 10
((¬p∨¬q)∧p)∨((¬p∨¬q)∧q)   =   ((¬p∧p)∨(¬q∧p)∨((¬p∧q)∨(¬q∧q))   regel 11
((¬p∧p)∨(¬q∧p)∨((¬p∧q)∨(¬q∧q))   =   (⊥∨(¬q∧p)∨((¬p∧q)∨⊥)     regel 17
(⊥∨(¬q∧p)∨(⊥∨(¬q∧q))   =   (¬q∧p)∨(¬p∧q)     regel 1
 (¬q∧p)∨(¬p∧q)  =  (p∧¬q)∨(¬p∧q)  regel 3
(p∧¬q)∨(¬p∧q)   =   ¬(¬p∨q)∨¬(p∨¬q)  regel 9
¬(¬p∨q)∨¬(p∨¬q)   =   ¬((¬p∨q)∧(p∨¬q))  regel 8
Ik kom er niet uit, ik zit heel dichtbij maar weel niet wat de laaste stap zou zijn, ik zit vast met één ¬ aan bijde kanten

Deze opdracht was gemaakt met Kian Matton
Regel nummerz zijn gebaseerd op de regel nummers van het Fundementals Of AI document