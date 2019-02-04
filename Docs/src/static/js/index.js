function getTitle() {
  const pathArray = window.location.pathname.split('/');
  const path = pathArray[pathArray.indexOf('docs_haptik') + 1];

  return path
    .split('-')
    .map(word => word[0].toUpperCase() + word.slice(1))
    .join(' ');
}

document.addEventListener('DOMContentLoaded', function() {
  const title = getTitle();

  if (title === 'Docs_haptik') return;

  const DOMList = document.getElementsByClassName('headerTitleWithLogo');
  const headerTitleDOM = DOMList.length ? DOMList[0] : null;
  const newTitle = `Haptik Docs <span> | ${title}</span>`;
  if (headerTitleDOM && headerTitleDOM.innerHTML !== newTitle) {
    headerTitleDOM.innerHTML = `Haptik Docs <span> | ${title}</span>`;
  }
});
