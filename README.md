1. Опис алгоритмів 

Bucket Sort 

Bucket Sort -  це алгоритм сортування без порівняння, який працює шляхом розподілу елементів масиву на певну кількість сегментів. Кожне відро потім сортується за допомогою іншого алгоритму сортування (у нашому випадку ми використали сортування вставкою), і відсортовані сегменти об’єднуються назад у вихідний масив.  

Властивості: 

- Не є алгоритмом in place 

- Stable (елементи з однаковим значенням зберігають свій відносний порядок) 

- Time complexity: O(n + k) де n — кількість елементів у вхідному масиві, а k — кількість сегментів. 

- Memory complexity: O(n + k) 

Shell Sort 

Shell Sort є простим і ефективним варіантом сортування вставкою. Він працює шляхом порівняння елементів, які знаходяться на певній відстані один від одного, і поступового зменшення відстані, доки елементи не стануть поруч. На цьому етапі алгоритм виконує стандартне сортування вставкою для решти несортованих елементів. 

Властивості: 

- Є алгоритмом in place 

- Unstable (елементи з однаковим значенням можуть не зберігати свій відносний порядок) 

- Time complexity: O(n^2) 

- Memory complexity: O(1) 

MergeSort 

MergeSort - це алгоритм сортування за принципом «розділяй і володарюй», який ділить масив на дві половини, сортує кожну половину, а потім об’єднує відсортовані половини.. 

Властивості: 

- Не є алгоритмом in place 

- Stable (елементи з однаковим значенням зберігають свій відносний порядок) 

- Time complexity: O(n log n) in the worst case 

- Memory complexity: O(n) 
   Псевдокод: 

 3. Результати експериментів  

Провівши експерименти з трьома алгоритмами сортування, ми можемо зробити такі висновки щодо їх ефективності: 
       
 Bucket Sort: 

Алгоритм показав високу швидкість роботи навіть для великих масивів. 

Споживання пам'яті алгоритмом велике через створення додаткових сегментів. 

Алгоритм - not in-pace та not stable. 

Shell Sort: 

Алгоритм показав найнижчу швидкість роботи порівняно з іншими алгоритмами для великих масивів. 

Споживання пам'яті алгоритмом низьке. 

Алгоритм  є in-place, але не stable. 

MergeSort: 

Алгоритм показав помірну швидкість роботи. 

Споживання пам'яті алгоритмом велике через необхідність додаткової пам'яті для злиття. 

Алгоритм не in-place, але він stable. 

Алгоритм не in-place, але він stable. 
Підсумовуючи, вибір алгоритму сортування залежить від конкретних вимог завдання. 
Якщо швидкість роботи має велике значення, то Bucket Sort — прекрасним вибором, особливо для великих масивів. 
Якщо споживання пам’яті недостатньо, то Shell Sort є чудовим варіантом.
Якщо стабільність є вимогою, то MergeSort є хорошим варіантом. 
