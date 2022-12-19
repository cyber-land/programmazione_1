E21 (14.1 + alcune slide)

come analizzare un algoritmo:
correttezza
- dimostrazione formale (matematica)
- ispezione formale
utilizzo delle risorse
- tempo di esecuzione
- utilizzo della memoria
semplicità
- facile da capire e mantenere

Complessità: "Dimensione dell’input" → "Tempo"

|f(n)|n = 10^1|n = 10^2|n = 10^3|n = 10^4|tipo|
|-|-|-|-|-|-|
|1|1|1|1|1|costante|
|log n|3|6|9|13|logaritmico|
|√n|3|10|31|100|sublineare|
|n|10|10^2|10^3|10^4|lineare|
|n log n|30|664|~10^4|~10^5|loglineare|
|n^2|10^2|10^4|10^6|10^8|quadratico|
|n^3|10^3|10^6|10^9|10^12|cubico|
|2^n|~10^3|~10^30|~10^300|~10^3000|esponenziale|
|n!|10!|(10^2)!|(10^3)!|(10^4)!|fattoriale|
|n^n|10^10|||||

**notazione asintotica**

O: O-grande
limite superiore asintotico
Per tutti gli input, l’algoritmo costa al più f (n)
f (n) = Ω(g(n))
f (n) è “Omega grande” di g(n)
f (n) cresce al più come g(n)

Ω: omega-grande
limite asintotico inferiore
Per tutti gli input, l’algoritmo costa almeno f (n)
f (n) cresce almeno quanto g(n)

Θ: theta
L’algoritmo richiede Θ(f (n)) per tutti gli input
f (n) cresce esattamente come g(n)
f (n) = Θ(g(n)) se e solo se f (n) = O(g(n)) e f (n) = Ω(g(n))

**tipologia di analisi**

caso pessimo
Il tempo di esecuzione nel caso peggiore è un limite superiore al tempo di esecuzione per qualsiasi input

caso medio
Distribuzione uniforme

caso ottimo
Può avere senso se si hanno informazioni particolari sull’input

---

stima del tempo di esecuzione per algoritmi:

**iterativi**
operazioni semplici: T(n) = O(1)
loops: T(n) = o(cicli * O(corpo))
if-else: O( max( O(sx), O(dx) ) )

**ricorsivi**
espresso mediante un equazione di ricorrenza
Sono necessarie tecniche specifiche per risolvere le equazioni di ricorrenza:

**metodo iterativo**
- Si itera la regola induttiva di T(n) in termini di n e del caso base.
- Si richiede poi di solito la manipolazione delle somme:
Kni i = n(n+1)/2

T(n) = T(n/2) + c = T(n/4) + c + c = T(n/8) + c + c + c
Alla i-esima iterazione abbiamo:
T(n) = T(n/2^i) + ic
L’iterazione raggiunge 1 quando:
n = 2^i, ovvero quando i = log(n), quindi
T(n) = c + log(n)c
E quindi possiamo dire che T(n) = O(log(n))

**metodo di sostituzione**
- Si ipotizza una possibile soluzione.
- Si sostituisce l’ipotetica soluzione nei casi base e induttivo.
- Si dimostra la correttezza della ipotesi tramite induzione matematica.

---

**manca il materiale:**
- alberi di ricorsione
- divide et impera
- peggiore, medio, migliore
- o-grande, omega Ω (limite inferiore), tetha θ (limite sia sup che inf)
- la complessità di algoritmi in-place è Ω^2
