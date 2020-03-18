var OriginTitle = document.title;
var titleTime;
document.addEventListener('visibilitychange', function() {
  if (document.hidden) {
    $('[rel="icon"]').attr('href', "/img/TEP.ico");
    document.title = '╭(°A°`)╮ 崩溃啦 ~';
    clearTimeout(titleTime);
  } else {
    $('[rel="icon"]').attr('href', "/favicon.ico");
    document.title = '(ฅ>ω<*ฅ) 又好了~';
    titleTime = setTimeout(function() { document.title = OriginTitle; }, 2000);
  }
});
