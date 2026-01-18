
function fadeAndReplace(textToReplace) {
    let delay = 500;

    let introFade = document.getElementById('introFade');
    
    introFade.classList.add('fade-out');
    
    setTimeout(function() {
      introFade.textContent = textToReplace;
      introFade.classList.add('fade-in');  

      setTimeout(function() {
        introFade.classList.remove('fade-out');
        introFade.classList.remove('fade-in');
      }, delay);

    }, delay);  
}


function repeatFade() {
    let count = 0;

    function startFade() {
        setTimeout(function() {
            fadeAndReplace(' Web developer');
        }, 2000);

        setTimeout(function() {
            fadeAndReplace(' Programmer', 500);
        }, 6000);

        setTimeout(function() {
            fadeAndReplace('n App Developer', 500);
        }, 10000);

        count++;

        if (count >= 40) {
            clearInterval(interval);
        }
    }
    startFade();
    let interval = setInterval(startFade, 12000);
}

repeatFade();

// -----------------------------------------------------------------------------------------------------------

document.querySelectorAll('a[href^="#"]').forEach(anchor => {
    anchor.addEventListener('click', function(e) {
        e.preventDefault();

        const target = document.querySelector(this.getAttribute('href'));

        if (target) {
            target.scrollIntoView({
                behavior: 'smooth',
                block: 'start'
            });
        }
    });
});

// -----------------------------------------------------------------------------------------------------------

const mediaQuery = window.matchMedia('(max-width: 940px)');
function handleMediaQueryChange(e) {
  if (e.matches) {
    let navs = document.getElementsByClassName(".mobLi");
    
    navs.forEach(element => {
        navs.style.display = 'none';
    });
  }
}

mediaQuery.addEventListener('change', handleMediaQueryChange);
handleMediaQueryChange(mediaQuery);

// -------------------------------------------------------------------------------------------------------

document.getElementById('email').addEventListener('click', function() {
    window.location.href = 'mailto:theanshkukreja@gmail.com';
});

document.getElementById('phone').addEventListener('click', function() {
    window.location.href = 'tel:+918096500009';
});
